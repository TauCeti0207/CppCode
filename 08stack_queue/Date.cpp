// Date.cpp
#include "Date.h"
#include <stdexcept>
namespace yzq
{
	// 判断是否为闰年
	bool Date::isLeapYear(int y) const
	{
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	}

	// 获取指定月份的天数
	// 函数后面加上 const 表明函数不会修改对象的状态
	int Date::getDaysInMonth(int y, int m) const
	{
		// static 节省内存，声明为 static 的变量存储在静态存储区
		// const 防止数组被修改
		static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		// 判断闰年
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

	// 拷贝构造函数 不写也可以，编译器默认生成就够用，内置类型浅拷贝
	Date::Date(const Date &other)
		: _year(other._year), _month(other._month), _day(other._day)
	{
		// std::cout << "copy constructor: " << this << std::endl;
	}

	// 赋值运算符重载
	// 加上 const，函数内部不会修改other所引用的对象，
	// 允许接受常量对象作为参数，临时变量也是具有常性的
	// 出了作用域，对象还在，就可以用传引用返回
	// 为了支持连续赋值 D1 = D2 = D3，返回值需要是 Date 类型
	Date &Date::operator=(const Date &other)
	{
		// 针对 d1 = d1 这种情况
		if (this != &other)
		{
			_year = other._year;
			_month = other._month;
			_day = other._day;
		}
		return *this;
	}

	// 析构函数
	Date::~Date()
	{
		// std::cout << "destructor: " << this << std::endl;
	}

	// const 修饰是让 const 对象也可以调用，同时也防止函数修改成员变量
	void Date::print() const
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}

	// 可以构成重载，一个是参数是 const Date* 一个参数是 Date*，参数类型不同的函数重载
	void Date::print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}

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
#if 0
	if (_year < other._year)
	{
		return true;
	}
	else if (_year == other._year && _month < other._month)
	{
		return true;
	}
	else if (_year == other._year && _month == other._month && _day < other._day)
	{
		return true;
	}
	else
	{
		return false;
	}
#elif 1
		return (_year < other._year) ||
			   (_year == other._year && _month < other._month) ||
			   (_year == other._year && _month == other._month && _day < other._day);
#endif
	}

	bool Date::operator<=(const Date &other) const
	{
		// 复用<、==运算符重载
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
	// 前置++
	Date &Date::operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++ 返回++以前的值
	Date Date::operator++(int)
	{
		// 要付出两次拷贝的代价
		Date temp = *this;
		*this += 1;
		return temp;
	}

	// 前置--
	Date &Date::operator--()
	{
		*this -= 1;
		return *this;
	}

	// 后置--
	Date Date::operator--(int)
	{
		Date temp = *this;
		*this -= 1;
		return temp;
	}

#if 0
// 日期加减天数运算符重载
Date Date::operator+(int days) const
{
	// 考虑 days 为负的情况
	if (days < 0)
	{
		return *this - (-days);
	}

	// 第一次拷贝
	Date result = *this;
	while (days > 0)
	{
		int daysInMonth = result.getDaysInMonth(result._year, result._month);
		if (result._day + days <= daysInMonth)
		{
			result._day += days;
			days = 0;
		}
		else // 加上 days 后超过当月天数
		{
			// 月进位
			days -= (daysInMonth - result._day + 1);
			result._day = 1;
			++result._month;
			if (result._month > 12)
			{
				// 年进位
				result._month = 1;
				++result._year;
			}
		}
	}
	// 第二次拷贝，返回临时变量也是一种拷贝
	return result;
}

Date Date::operator-(int days) const
{
	// 考虑 days 为负的情况
	if (days < 0)
	{
		return *this + (-days);
	}

	// 这里其实也是调用拷贝构造完成
	// 使用一个已存在的对象去初始化另一个新对象时，就会调用拷贝构造函数
	// 等价与 Date result(*this)
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
	// 出了作用域对象不在了，不能用引用返回
	return result;
}

Date &Date::operator+=(int days)
{
	// 复用 operator+
	// 两次拷贝+一次赋值
	*this = *this + days;
	return *this;
}

Date &Date::operator-=(int days)
{
	// 复用 operator-
	*this = *this - days;
	return *this;
}

#elif 1
	// 下面这种+去复用+=、-去复用-=比上面的写法更优，上面的+=有两次拷贝和一次赋值，下面的+= 只有 0 次拷贝
	// 日期加减天数运算符重载
	Date Date::operator+(int days) const
	{
		// 复用+=
		// 第一次拷贝
		Date tmp = *this;
		tmp += days;
		// 第二次拷贝，共计两次拷贝
		return tmp;
	}

	Date Date::operator-(int days) const
	{
		// 复用 -=
		Date tmp = *this;
		tmp -= days;
		return tmp;
	}

	// 这样实现的+= 只有 0 次拷贝
	Date &Date::operator+=(int days)
	{
		// 考虑 days 为负的情况
		if (days < 0)
		{
			return *this -= (-days);
		}

		while (days > 0)
		{
			int daysInMonth = getDaysInMonth(_year, _month);
			if ((*this)._day + days <= daysInMonth)
			{
				_day += days;
				days = 0;
			}
			else // 加上 days 后超过当月天数
			{
				// 月进位
				days -= (daysInMonth - _day + 1);
				_day = 1;
				++_month;
				if (_month > 12)
				{
					// 年进位
					_month = 1;
					++_year;
				}
			}
		}
		return *this;
	}

	Date &Date::operator-=(int days)
	{
		// 考虑 days 为负的情况
		if (days < 0)
		{
			return *this += (-days);
		}

#if 0
	while (days > 0)
	{
		if (_day - days >= 1)
		{
			_day -= days;
			days = 0;
		}
		else
		{
			days -= _day;
			--_month;
			if (_month < 1)
			{
				// 今年已经借完了，要借上一年了
				_month = 12;
				--_year;
			}
			_day = getDaysInMonth(_year, _month);
		}
	}
#elif 1
		_day -= days;
		while (_day <= 0)
		{
			--_month;
			if (_month < 1)
			{
				_month = 12;
				--_year;
			}
			_day += getDaysInMonth(_year, _month);
		}
#endif
		return *this;
	}

#endif

	// 日期相减，返回两个日期之间的天数
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
		// 返回天数差
		return (*this < other) ? -days : days;
	}

	// 输出日期
	// 为了支持连续的输入输出，返回值也得是ostream类型
	std::ostream &operator<<(std::ostream &os, const Date &date)
	{
		os << date._year << "-" << date._month << "-" << date._day;
		return os;
	}

	// 输入日期
	std::istream &operator>>(std::istream &is, Date &date)
	{
		is >> date._year >> date._month >> date._day;
		return is;
	}
}