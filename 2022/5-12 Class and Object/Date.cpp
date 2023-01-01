#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(year >= 0 && month > 0 && month < 13);
	// 数组存储平年每个月天数
	// 这个函数会被频繁调用，应定义为inline 且数组放在静态区，避免反复开辟
	// 线程安全问题，加const
	const static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	if (month == 2 && IsLeapYear(year))
	{
		//判断顺序交换一下，只有2月才需要判断是否是闰年，提高效率
		day = 29;
	}
	return day;
}

// 缺省参数一般就写在声明中
Date::Date(int year, int month, int day)
{
	//检查日期合法性
	if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day < GetMonthDay(year, month))
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

void Date::Print() const // 等价于 void Date::Print(const Date* const this)
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}


// 这些都是比较短的函数，可以考虑内联
// 不过注意：内联函数不支持声明和定义在2个文件中
// 所以如果要内联的话，就直接放到.h文件中的类里面就行了
// 只需要先实现一个> == 剩下的都可以去复用
bool Date::operator==(const Date& d) const
{
	return _year == d._year 
		&& _month == d._month 
		&& _day == d._day;
}
bool Date::operator<(const Date& d) const
{
	if ((_year < d._year) ||
		(_year == d._year && _month < d._month) ||
		(_year == d._year && _month == d._month && _day < d._day))
		return true;
	return false;
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator<=(const Date& d) const
{
	return ((*this < d) || (*this == d));
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

// d1 += 10
// 出了作用域对象还在可以传引用返回，不传也行，无非就是多一次拷贝而已。
Date& Date::operator+=(int day)
{
	// 考虑day为负数
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		// 要考虑一次加的天比较大，需要多运算几次，因此不能用if
		while (_day > GetMonthDay(_year, _month))
		{
			// 天满了，减去当月的天数，月++
			_day -= GetMonthDay(_year, _month);
			++_month;
			// 月满了，要回到1月，年++
			if (_month > 12)
			{
				_month = 1;
				++_year;
			}
		}
	}
	return *this;
}
// += 返回的是d本身
// 可以实现`(i += 10) += 10; (d1 += 10) += 10; `变成了左值（可修改的）

// d1 + 10 d1不变
Date Date::operator+(int day) const
{
	// 创建临时对象
	Date ret(*this); // 调用拷贝构造
	//复用operator+=
	ret += day;
	return ret; // 临时对象不能用引用返回，出了作用域，临时对象就销毁了
}

// d1 -= 100
Date& Date::operator-=(int day)
{
	//考虑day是负数
	if (day < 0)
	{
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
			//加上上个月的天数	借位
			int preMonthDay = GetMonthDay(_year, _month);
			_day += preMonthDay;
		}
	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;//出了作用域就被销毁了
}

// ++d & d++
Date& Date::operator++()
{
	*this += 1;
	return *this; // 前置++是先++，返回的是++之后的值
}

Date Date::operator++(int) // 后置++  语法规定的
{
	// int 参数不需要给实参，仅仅是为了构成重载，从而区分前置++ 和后置++而已
	Date tmp(*this);
	*this += 1;
	return tmp; //后置++ 先使用d再++ 返回的是++之前的值
}

Date& Date::operator--() // 前置--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int) // 后置--
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//d1 - d2  日期+日期没有意义
int Date::operator-(const Date& d) const
{
	//让小的不断++，直到==max
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
	return count * flag;
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
// 流提取，提取到的值要放到d里面，因此d不能用const修饰
std::istream& operator>>(std::istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	// 进行非法检查
	if (d._year >= 0 && d._month >= 1 && d._month <= 12 && d._day >= 1 && d._day <= d.GetMonthDay(d._year, d._month))
	{
		return in;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
}