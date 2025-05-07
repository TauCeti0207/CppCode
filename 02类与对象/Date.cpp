// Date.cpp
#include "Date.h"
#include <stdexcept>

// 判断是否为闰年
bool Date::isLeapYear(int y) const
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 获取指定月份的天数
int Date::getDaysInMonth(int y, int m) const
{
	static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (m == 2 && isLeapYear(y))
	{
		return 29;
	}
	return days[m];
}

// 构造函数
Date::Date(int y, int m, int d) : _year(y), _month(m), _day(d)
{
	if (!isValidDate())
	{
		throw std::invalid_argument("Invalid date");
	}
	// std::cout << "this: " << this << std::endl;
}

// 拷贝构造函数
Date::Date(const Date &other) : _year(other._year), _month(other._month), _day(other._day) {}

// 赋值运算符重载
Date &Date::operator=(const Date &other)
{
	if (this != &other)
	{
		_year = other._year;
		_month = other._month;
		_day = other._day;
	}
	return *this;
}

// 析构函数
Date::~Date() {}

// 获取日期信息
int Date::getYear() const { return _year; }
int Date::getMonth() const { return _month; }
int Date::getDay() const { return _day; }

// 设置日期信息
void Date::setYear(int y)
{
	int oldYear = _year;
	_year = y;
	if (!isValidDate())
	{
		_year = oldYear;
		throw std::invalid_argument("Invalid year");
	}
}

void Date::setMonth(int m)
{
	int oldMonth = _month;
	_month = m;
	if (!isValidDate())
	{
		_month = oldMonth;
		throw std::invalid_argument("Invalid month");
	}
}

void Date::setDay(int d)
{
	int oldDay = _day;
	_day = d;
	if (!isValidDate())
	{
		_day = oldDay;
		throw std::invalid_argument("Invalid day");
	}
}

// 日期合法性检查
bool Date::isValidDate() const
{
	if (_year < 1 || _month < 1 || _month > 12 || _day < 1)
	{
		return false;
	}
	return _day <= getDaysInMonth(_year, _month);
}

// 日期比较运算符重载
bool Date::operator==(const Date &other) const
{
	return _year == other._year && _month == other._month && _day == other._day;
}

bool Date::operator!=(const Date &other) const
{
	return !(*this == other);
}

bool Date::operator<(const Date &other) const
{
	if (_year < other._year)
		return true;
	if (_year > other._year)
		return false;
	if (_month < other._month)
		return true;
	if (_month > other._month)
		return false;
	return _day < other._day;
}

bool Date::operator<=(const Date &other) const
{
	return *this < other || *this == other;
}

bool Date::operator>(const Date &other) const
{
	return !(*this <= other);
}

bool Date::operator>=(const Date &other) const
{
	return !(*this < other);
}

// 日期自增自减运算符重载
Date &Date::operator++()
{
	++_day;
	if (_day > getDaysInMonth(_year, _month))
	{
		_day = 1;
		++_month;
		if (_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}

Date Date::operator++(int)
{
	Date temp = *this;
	++(*this);
	return temp;
}

Date &Date::operator--()
{
	--_day;
	if (_day < 1)
	{
		--_month;
		if (_month < 1)
		{
			_month = 12;
			--_year;
		}
		_day = getDaysInMonth(_year, _month);
	}
	return *this;
}

Date Date::operator--(int)
{
	Date temp = *this;
	--(*this);
	return temp;
}

// 日期加减天数运算符重载
Date Date::operator+(int days) const
{
	Date result = *this;
	while (days > 0)
	{
		int daysInMonth = result.getDaysInMonth(result._year, result._month);
		if (result._day + days <= daysInMonth)
		{
			result._day += days;
			days = 0;
		}
		else
		{
			days -= (daysInMonth - result._day + 1);
			result._day = 1;
			++result._month;
			if (result._month > 12)
			{
				result._month = 1;
				++result._year;
			}
		}
	}
	return result;
}

Date Date::operator-(int days) const
{
	Date result = *this;
	while (days > 0)
	{
		if (result._day - days >= 1)
		{
			result._day -= days;
			days = 0;
		}
		else
		{
			days -= result._day;
			--result._month;
			if (result._month < 1)
			{
				result._month = 12;
				--result._year;
			}
			result._day = result.getDaysInMonth(result._year, result._month);
		}
	}
	return result;
}

int Date::operator-(const Date &other) const
{
	Date earlier = (*this < other) ? *this : other;
	Date later = (*this < other) ? other : *this;
	int days = 0;
	while (earlier != later)
	{
		++earlier;
		++days;
	}
	return (*this < other) ? -days : days;
}

// 输出日期
std::ostream &operator<<(std::ostream &os, const Date &date)
{
	os << date._year << "-" << date._month << "-" << date._day;
	return os;
}

// 输入日期
std::istream &operator>>(std::istream &is, Date &date)
{
	int y, m, d;
	is >> y >> m >> d;
	try
	{
		date = Date(y, m, d);
	}
	catch (const std::invalid_argument &e)
	{
		is.setstate(std::ios::failbit);
	}
	return is;
}