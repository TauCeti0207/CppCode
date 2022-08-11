#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	assert(year >= 0 && month > 0 && month < 13);
	// ����洢ƽ��ÿ��������
	// ��������ᱻƵ�����ã�Ӧ����Ϊinline ��������ھ�̬�������ⷴ������
	// �̰߳�ȫ���⣬��const
	const static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	if (month == 2 && IsLeapYear(year))
	{
		//�ж�˳�򽻻�һ�£�ֻ��2�²���Ҫ�ж��Ƿ������꣬���Ч��
		day = 29;
	}
	return day;
}

// ȱʡ����һ���д��������
Date::Date(int year, int month, int day)
{
	//������ںϷ���
	if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day < GetMonthDay(year, month))
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

void Date::Print() const // �ȼ��� void Date::Print(const Date* const this)
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}


// ��Щ���ǱȽ϶̵ĺ��������Կ�������
// ����ע�⣺����������֧�������Ͷ�����2���ļ���
// �������Ҫ�����Ļ�����ֱ�ӷŵ�.h�ļ��е������������
// ֻ��Ҫ��ʵ��һ��> == ʣ�µĶ�����ȥ����
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
// ��������������ڿ��Դ����÷��أ�����Ҳ�У��޷Ǿ��Ƕ�һ�ο������ѡ�
Date& Date::operator+=(int day)
{
	// ����dayΪ����
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		// Ҫ����һ�μӵ���Ƚϴ���Ҫ�����㼸�Σ���˲�����if
		while (_day > GetMonthDay(_year, _month))
		{
			// �����ˣ���ȥ���µ���������++
			_day -= GetMonthDay(_year, _month);
			++_month;
			// �����ˣ�Ҫ�ص�1�£���++
			if (_month > 12)
			{
				_month = 1;
				++_year;
			}
		}
	}
	return *this;
}
// += ���ص���d����
// ����ʵ��`(i += 10) += 10; (d1 += 10) += 10; `�������ֵ�����޸ĵģ�

// d1 + 10 d1����
Date Date::operator+(int day) const
{
	// ������ʱ����
	Date ret(*this); // ���ÿ�������
	//����operator+=
	ret += day;
	return ret; // ��ʱ�����������÷��أ�������������ʱ�����������
}

// d1 -= 100
Date& Date::operator-=(int day)
{
	//����day�Ǹ���
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
			//�����ϸ��µ�����	��λ
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
	return tmp;//����������ͱ�������
}

// ++d & d++
Date& Date::operator++()
{
	*this += 1;
	return *this; // ǰ��++����++�����ص���++֮���ֵ
}

Date Date::operator++(int) // ����++  �﷨�涨��
{
	// int ��������Ҫ��ʵ�Σ�������Ϊ�˹������أ��Ӷ�����ǰ��++ �ͺ���++����
	Date tmp(*this);
	*this += 1;
	return tmp; //����++ ��ʹ��d��++ ���ص���++֮ǰ��ֵ
}

Date& Date::operator--() // ǰ��--
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int) // ����--
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//d1 - d2  ����+����û������
int Date::operator-(const Date& d) const
{
	//��С�Ĳ���++��ֱ��==max
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
	return count * flag;
}

std::ostream& operator<<(std::ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}
// ����ȡ����ȡ����ֵҪ�ŵ�d���棬���d������const����
std::istream& operator>>(std::istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	// ���зǷ����
	if (d._year >= 0 && d._month >= 1 && d._month <= 12 && d._day >= 1 && d._day <= d.GetMonthDay(d._year, d._month))
	{
		return in;
	}
	else
	{
		cout << "�Ƿ�����" << endl;
		assert(false);
	}
}