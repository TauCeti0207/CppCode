// person.cpp
#include "Person.h"

// 构造函数实现
Person::Person(const char *name, const char *sex, int age)
{
	if (name)
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}
	else
	{
		_name = new char[1];
		_name[0] = '\0';
	}

	if (sex)
	{
		_sex = new char[strlen(sex) + 1];
		strcpy(_sex, sex);
	}
	else
	{
		_sex = new char[1];
		_sex[0] = '\0';
	}

	_age = age;
}

// 拷贝构造函数实现
Person::Person(const Person &other)
{
	if (other._name)
	{
		_name = new char[strlen(other._name) + 1];
		strcpy(_name, other._name);
	}
	else
	{
		_name = new char[1];
		_name[0] = '\0';
	}

	if (other._sex)
	{
		_sex = new char[strlen(other._sex) + 1];
		strcpy(_sex, other._sex);
	}
	else
	{
		_sex = new char[1];
		_sex[0] = '\0';
	}

	_age = other._age;
}

// 赋值运算符重载实现
Person &Person::operator=(const Person &other)
{
	if (this != &other)
	{
		delete[] _name;
		delete[] _sex;

		if (other._name)
		{
			_name = new char[strlen(other._name) + 1];
			strcpy(_name, other._name);
		}
		else
		{
			_name = new char[1];
			_name[0] = '\0';
		}

		if (other._sex)
		{
			_sex = new char[strlen(other._sex) + 1];
			strcpy(_sex, other._sex);
		}
		else
		{
			_sex = new char[1];
			_sex[0] = '\0';
		}

		_age = other._age;
	}
	return *this;
}

// 析构函数实现
Person::~Person()
{
	delete[] _name;
	delete[] _sex;
}

// 显示信息函数实现
void Person::show()
{
	std::cout << _name << "  " << _sex << "  " << _age << std::endl;
}