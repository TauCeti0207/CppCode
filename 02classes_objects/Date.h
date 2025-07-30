/*
 * @Descripttion:
 * @Author: tauceti0207
 * @version:
 * @Date: 2025-05-07 00:50:38
 * @LastEditors: tauceti0207
 * @LastEditTime: 2025-05-09 15:13:07
 */
// Date.h
#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
	// 友元声明
	friend std::ostream &operator<<(std::ostream &os, const Date &date);
	friend std::istream &operator>>(std::istream &is, Date &date);

private:
	int _year; // 这里只是声明
	int _month;
	int _day;

	// 判断是否为闰年
	bool isLeapYear(int y) const;
	// 获取指定月份的天数
	int getDaysInMonth(int y, int m) const;

public:
	// 构造函数
	Date(int y = 1900, int m = 1, int d = 1);
	// 拷贝构造函数
	Date(const Date &other);
	// 赋值运算符重载
	Date &operator=(const Date &other);
	// 析构函数
	~Date();

	// 输出日期
	void print() const;
	void print();

	// 获取日期信息
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	// 设置日期信息
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);

	// 日期合法性检查
	bool isValidDate() const;

	// 日期比较运算符重载
	// 只读函数，不涉及修改内部成员的，都建议加上 const
	bool operator==(const Date &other) const;
	bool operator!=(const Date &other) const;
	bool operator<(const Date &other) const;
	bool operator<=(const Date &other) const;
	bool operator>(const Date &other) const;
	bool operator>=(const Date &other) const;

	// 日期自增自减运算符重载
	Date &operator++();	  // 前置自增
	Date operator++(int); // 后置自增
	Date &operator--();	  // 前置自减
	Date operator--(int); // 后置自减

	// 日期加减天数运算符重载
	Date operator+(int days) const;
	Date operator-(int days) const;
	int operator-(const Date &other) const;
	Date &operator+=(int days);
	Date &operator-=(int days);

	// 基本没有实现价值 除非你不想让别人获取Date类对象地址，才需要自己实现
	Date *operator&()
	{
		return this;
		// return nullptr; //不想让别人拿到对象地址，才需要去写取地址运算符重载
	}

	const Date *operator&() const
	{
		return this;
	}

#if 0
	// 举例 const 修饰位置
	const int &func() const
	{
		static int ret;
		return ret;
	}
#endif
};

// 全局函数
std::ostream &operator<<(std::ostream &os, const Date &date);
std::istream &operator>>(std::istream &is, Date &date);

#endif // DATE_H