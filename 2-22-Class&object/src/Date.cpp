#include "Date.h"

inline int GetMonthDay(int year, int month)
{
    //����洢ƽ��ÿ��������
    //��������ᱻƵ�����ã�Ӧ����Ϊinline ��������ھ�̬�������ⷴ������
    static int dayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day = dayArray[month];
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) // 4��һ���Ұ��겻�󣬻���400����
    {
        //�ж�˳�򽻻�һ�£�ֻ��2�²���Ҫ�ж��Ƿ������꣬���Ч��
        day = 29;
    }
    return day;
}

//ȱʡ����һ���д��������
Date::Date(int year, int month, int day) //���캯��
{
    //������ںϷ���
    if (year >= 0 && month > 0 && month < 13 && day > 0 && day < GetMonthDay(year, month))
    {
        _year = year;
        _month = month;
        _day = day;
    }
    else
    {
        cout << "�Ƿ�����" << endl;
        assert(false);
    }
}
void Date::Print()
{
    cout << _year << "��" << _month << "��" << _day << "��" << endl;
}

// d += 100 ��ı�d
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
            // 1.�����ˣ���ȥ���µ���������+1
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month > 12)
            {
                // 2.�����ˣ���+1�����ó�1
                ++_year;
                _month = 1;
            }
        }
    }
    return *this; //*this ���Ǽ����������
    //����ʵʵ�ֵĹ����� += ������ +
}

// d1 + 10
Date Date::operator+(int day)
{
    //������ʱ����
    Date ret(*this); //���ÿ�������
    //����operator+=
    ret += day;
    return ret; //��ʱ�����������÷��أ�������������ʱ�����������
}
// d1 -= 100  d1 -= -100
Date &Date::operator-=(int day)
{
    //����day�Ǹ���
    if (day < 0)
    {
        //����
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
            //�����ϸ��µ�����
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
Date &Date::operator++() //ǰ��++ d++ ++d ��ͬ�����ڷ���ֵ��ͬ
{
    *this += 1;
    return *this; //ǰ��++����++
}

Date Date::operator++(int) //����++  C++֮���涨��
{
    // int ��������Ҫ��ʵ�Σ���Ϊֻ��Ϊ�˹������أ��Ӷ�����ǰ��++ �ͺ���++����
    Date tmp(*this);
    *this += 1;
    return tmp; //����++ ��ʹ��d��++ ���ص���++֮ǰ��ֵ
}

Date &Date::operator--() //ǰ��--
{
    *this -= 1;
    return *this;
}

Date Date::operator--(int) //����--
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}

//ֻ��Ҫ��ʵ��һ��> == ʣ�µĶ�����ȥ����
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
    //˼·����С�Ĳ���++��ֱ��==max
    Date max = *this;
    Date min = d;
    int flag = 1;
    if (*this < d)
    {
        //�жϴ���
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